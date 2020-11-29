{- CS 152 Homework 6
   Team Name: The Curly Brackets-}

import  Data.Char

takeRest :: (a -> Bool) -> ([a], [a]) -> ([a], [a])
takeRest p (str, []) = (str, [])
takeRest p (str, (head:tail)) = if (p head) then (takeRest p (str++[head], tail)) else (str, head:tail)

data Token = Operator Char
           | OpenParen
           | CloseParen
           | Number Float
    deriving (Show, Eq)

data ParseTree = NumNode Float
               | OpNode Char [ParseTree]
          deriving Show

-- STEP 1

scan :: String -> [Token]
scan "" = []
scan (' ':tail) = scan tail
scan ('(':tail) = (OpenParen):(scan tail)
scan (')':tail) = (CloseParen):(scan tail)

scan ('+':tail) = (Operator '+'):(scan tail)
scan ('-':tail) = (Operator '-'):(scan tail)
scan ('*':tail) = (Operator '*'):(scan tail)
scan ('/':tail) = (Operator '/'):(scan tail)

scan (head:tail)
    | (isDigit head) = (let (str, rest) = (takeRest (\x -> (isDigit x) || (x == '.')) ("", head:tail)) in (Number (read str)):(scan rest))
    | otherwise      = error ("Illegal Character: "++[head])

-- STEP 2: uncomment each step as you work on it

recognize :: [Token] -> Bool
recognize (OpenParen:tokens) = fst (expr (OpenParen:tokens))
recognize (Number num:[]) = True
recognize _ = False

expr :: [Token] -> (Bool, [Token])
expr (OpenParen:Operator _:tail) = (let (op, r1) = operands tail
                                                        in case r1 of
                                                            CloseParen:tail2 -> (op, tail2)
                                                            _ -> error "Invalid expression")
expr (Number _:tail) = (True, tail)
expr (CloseParen:tokens) = error "unexpected )"
expr (_) = error "Invalid expression"


operands :: [Token] -> (Bool, [Token])
operands (tokens) = (let (ex, r1) = expr tokens
                                in case r1 of
                                    (CloseParen:tail) -> (ex, r1)
                                    tokens2 -> operands tokens2)

check:: String -> Bool
check = recognize.scan

-- STEP 3: uncomment each step as you work on it

build :: [Token] -> ParseTree
build tokens
    | (recognize tokens) = fst (pexpr tokens)
    | otherwise = error "Invalid expression"

poperands :: [Token] -> ([ParseTree], [Token])
poperands tokens = (let (parseT, rest) = pexpr tokens
                                in case rest of
                                    (CloseParen:tail) -> ([parseT], rest)
                                    _ -> (let (pt, rest2) = poperands rest in (parseT:pt, rest2)))

pexpr :: [Token] -> (ParseTree, [Token])
pexpr (OpenParen:Operator op:rest) = (let (parseT, rest2) = poperands rest
                                                              in ((OpNode op parseT), (tail rest2)))
pexpr (Number num:[]) = (NumNode num, [])
pexpr (Number num:tail) = (NumNode num, tail)

parse:: String -> ParseTree
parse str = if (check str) then (build (scan str)) else error "Invalid expression"

-- STEP 4: uncomment each step as you work on it

eval :: ParseTree -> Float
eval (OpNode '+' tlist) = foldl (+) 0 (map eval tlist)

eval (OpNode '*' tlist) = foldl (*) 1 (map eval tlist)

eval (OpNode '-' (tlist:[])) = 0 - (eval tlist)
eval (OpNode '-' (tlist:tail)) = foldl (-) (eval tlist) (map eval tail)

eval (OpNode '/' (tlist:[])) = 1 / (eval tlist)
eval (OpNode '/' (tlist:tail)) = foldl (/) (eval tlist) (map eval tail)

eval (NumNode num) = num

interpret :: String -> Float
interpret str = if (check str) then (eval (build (scan str))) else error "Invalid expression"
