fatores :: Int -> [Int]
fatores 0 = []
fatores n = [ i | i <- [1..n `div` 2], n `mod` i == 0 ] ++ [n]

somatorio :: [Int] -> Int
somatorio [] = 0
somatorio (a:x) = a + somatorio x

perfeito :: Int -> Bool
perfeito n = somatorio (fatores n)- n == n
