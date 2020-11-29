{- CS 152 Homework 5
   Team Name: The Curly Brackets -}

import  Data.Char

-- Question 1
takeRest :: (a -> Bool) -> [a] -> [a]
-- Please Enter your code for question 1 here
takeRest p [] = []
takeRest p (head:tail) = if (p head) then (takeRest p tail) else (head:tail)



-- Question 2 - Uncomment the function type declaration below
shout ::  [String] -> String
-- Please Enter your code for question 2 here
shout [] = ""
shout arr = foldl (\x y -> x++y++"!") "" arr


-- Type Declaration for question 3
data Token = Operator
           | OpenParen
           | CloseParen
           | Identifier
           | Number
    deriving Show

-- Question 3 - - Uncomment the function type declaration below
tokenize :: String -> [Token]
-- Please Enter your code for question 3 here
tokenize "" = []

tokenize (' ':tail) = tokenize tail
tokenize ('(':tail) = (OpenParen):(tokenize tail)
tokenize (')':tail) = (CloseParen):(tokenize tail)

tokenize ('+':tail) = (Operator):(tokenize tail)
tokenize ('-':tail) = (Operator):(tokenize tail)
tokenize ('*':tail) = (Operator):(tokenize tail)
tokenize ('/':tail) = (Operator):(tokenize tail)

tokenize (head:tail)
    | (isAlpha head) = (Identifier):(tokenize (takeRest isAlpha tail))
    | (isDigit head) = (Number):(tokenize (takeRest (\x -> (isDigit x) || (x == '.')) tail))
    | otherwise      = error ("Illegal Character: "++[head])