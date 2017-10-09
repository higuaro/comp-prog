module P57 where

import Data.Ratio

p57 :: Int -> Int
p57 steps = foldl (\acc f -> if (lenDigits $ numerator f) > (lenDigits $ denominator f) then acc + 1 else acc) 0 (map sqrtCF [1..steps])
          where lenDigits n = length $ show n 

sqrtCF :: Int -> Rational
sqrtCF step 
       | step == 1 = 1 + (1 % 2)
       | otherwise = 1 + (1 / (sqrtContinuosFraction $ subtract 1 step))

sqrtContinuosFraction :: Int -> Rational
sqrtContinuosFraction expansion 
                      | expansion == 1 = 2 + (1 % 2)
                      | otherwise      = 2 + (1 / (sqrtContinuosFraction (subtract 1 expansion)))
                      

