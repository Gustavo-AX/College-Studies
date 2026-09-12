fatores :: Int -> [Int]
fatores 0 = []
fatores n = [ i | i <- [1..n `div` 2], n `mod` i == 0 ] ++ [n]

primo :: Int -> Bool
primo n = fatores n == [1,n]
