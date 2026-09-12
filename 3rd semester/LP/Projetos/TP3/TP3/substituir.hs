substituir :: Int -> Int -> [Int] -> [Int]
substituir _ _ [] = []
substituir x y (a:as)
  | a == x = [y] ++ substituir x y as 
  | otherwise = [a] ++ substituir x y as
