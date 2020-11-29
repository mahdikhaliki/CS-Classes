{- CS 152 Homework 7
   Team Name: The Curly Brackets -}

import  Data.Char

takeRest :: (a -> Bool) -> ([a], [a]) -> ([a], [a])
takeRest p (str, []) = (str, [])
takeRest p (str, (head:tail)) = if (p head) then (takeRest p (str++[head], tail)) else (str, head:tail)

data Token = Operator Char
           | OpenParen
           | CloseParen
           | Number Float
           | Let
           | Lambda
           | Identifier String
    deriving (Show, Eq)

data ParseTree = NumNode Float
               | OpNode Char [ParseTree]
               | IdentNode String
               | Binding ParseTree ParseTree
               | LetNode ParseTree ParseTree
               | LambdaNode String ParseTree
               | Application ParseTree ParseTree
    deriving Show

-- STEP 1
scan :: String -> [Token]
scan "" = []
scan (' ':tail) = scan tail
scan ('(':tail) = (OpenParen):(scan tail)
scan (')':tail) = (CloseParen):(scan tail)

scan (head: tail)
    | elem head "+-*/" = (Operator head):(scan tail)

scan ('l':'e':'t':' ':tail) = (Let):(scan tail)
scan ('l':'a':'m':'b':'d':'a':' ':tail) = (Lambda):(scan tail)

scan (head:tail)
    | (isDigit head) = (let (str, rest) = (takeRest (\x -> (isDigit x) || (x == '.')) ("", head:tail)) in (Number (read str)):(scan rest))
    | (head == '.') = (let (str, rest) = (takeRest (\x -> (isDigit x) || (x == '.')) ("", head:tail)) in (Number (read ('0':str))):(scan rest))
    | (isAlpha head) = (let (str, rest) = (takeRest (\x -> isAlpha x) ("", head:tail)) in (Identifier str):(scan rest))
    | otherwise      = error ("Illegal Character: "++[head])

-- STEP 2: uncomment each step as you work on it

build :: [Token] -> ParseTree
build (input) = (let (tree, tokens) = (expr input)
                                       in case tokens of
                                           [] -> tree
                                           _ -> error "Invalid input")

-- <operands> ->  <expr> [<operands>]
operands :: [Token] -> ([ParseTree], [Token])
operands (input) = (let (ex, rest) = expr input
                                in case rest of
                                    (CloseParen:_) -> ([ex], rest)
                                    tokens -> (let (op, rest2) = operands tokens in (ex:op, rest2)))

-- <expr> -> OPENPAREN OPERATOR <operands> CLOSEPAREN
--         |   NUMBER
--         | OPENPAREN LET OPENPAREN <binding> CLOSEPAREN <expr> CLOSEPAREN
--         | <application>
--         | IDENTIFIER
expr :: [Token] -> (ParseTree, [Token])
expr (OpenParen:Operator op:tail) = (let (trees, rest) = operands tail in case rest of
									(CloseParen:rest2) -> ((OpNode op trees), (rest2))
									_ -> error "Invalid expression")
expr (Number num:tail) = (NumNode num, tail)
expr (OpenParen:Let:OpenParen:tail) = (let (bind, rest) = binding tail
										in case rest of
											(CloseParen:rest2) -> (let (ex, rest3) = expr rest2 in case rest3 of
																	(CloseParen:rest4) -> (LetNode bind ex, rest4)
																	_ -> error "Invalid expression")
											_ -> error "Invalid expression")
expr (Identifier id:tail) = (IdentNode id, tail)
expr (input) = application input

-- <binding> -> OPENPAREN IDENTIFIER <expr> CLOSEPAREN
binding :: [Token] -> (ParseTree, [Token])
binding (OpenParen:Identifier id:tail) = (let (ex, rest) = expr tail in case rest of
                                                            CloseParen:tail2 -> ((Binding (IdentNode id) (ex)), tail2)
                                                            _ -> error "Invalid binding")
binding (_) = error "Invalid binding"

-- <function> -> OPENPAREN LAMBDA OPENPAREN IDENTIDIER CLOSEPAREN <expr> CLOSEPAREN
function :: [Token] -> (ParseTree, [Token])
function (OpenParen:Lambda:OpenParen:Identifier id:CloseParen:tail) = (let (ex, rest) = expr tail in case rest of
                                                            CloseParen:tail2 -> ((LambdaNode id ex), tail2)
                                                            _ -> error "Invalid function")
function (_) = error "Invalid function"

-- <application> ->  OPENPAREN <function> <expression> CLOSEPAREN
application :: [Token] -> (ParseTree, [Token])
application (OpenParen:tail) = (let (func, rest) = function tail in (let (ex, rest2) = expr rest in case rest2 of
								CloseParen:tail2 -> (Application func ex, tail2)
								_ -> error "Invalid application"))
application (_) = error "Invalid application"

parse:: String -> ParseTree
parse = build.scan

-- STEP 3: uncomment each step as you work on it

eval :: [(String, Float)] -> ParseTree -> Float
eval env (IdentNode str) = (let (num) = lookup str env
                            in case num of
                                Just x -> x
                                Nothing -> error "Undefined identifier")

eval env (LetNode (Binding (IdentNode str) exp1Tree) exp2Tree) = (let (num) = (eval env exp1Tree)
                                                                in eval ((str, num):env) exp2Tree)

eval env (Application (LambdaNode str exp1Tree) exp2Tree) = (let (num) = (eval env exp2Tree)
                                                                in eval ((str, num):env) exp1Tree)

eval env (OpNode '+' tlist) = foldl (+) 0 (map (eval env) tlist)

eval env (OpNode '*' tlist) = foldl (*) 1 (map (eval env) tlist)

eval env (OpNode '-' (tlist:[])) = 0 - (eval env tlist)
eval env (OpNode '-' (tlist:tail)) = foldl (-) (eval env tlist) (map (eval env) tail)

eval env (OpNode '/' (tlist:[])) = 1 / (eval env tlist)
eval env (OpNode '/' (tlist:tail)) = foldl (/) (eval env tlist) (map (eval env) tail)

eval env (NumNode num) = num

eval0 :: ParseTree -> Float
eval0 tree = eval [] tree

interpret :: String -> Float
interpret = eval0.build.scan
