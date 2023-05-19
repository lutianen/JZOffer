-- 求出每 3 个或 2 个不同数相加的和等于 10，该如何求解，有多少个解？
-- path: SQL\F0216.sql

CREATE TABLE F0216 (
    Num INT
);

INSERT INTO F0216 VALUES 
(1), (2), (3),
(4), (5), (6),
(7), (8), (9);

-- 思路 自联结 + 组合
SELECT A.Num NUM1, B.Num NUM2, C.Num NUM3 
FROM 
F0216 A, F0216 B, F0216 C
WHERE A.Num + B.Num + C.Num = 10 
    AND A.Num != B.Num
    AND A.Num != C.Num
    AND B.Num != C.Num
UNION ALL
SELECT A.Num NUM1, B.Num NUM2, NULL -- NULL 为了和前面保持一致
FROM 
F0216 A, F0216 B
WHERE A.Num + B.Num = 10 
    AND A.Num != B.Num;


-- 统计数量
SELECT * FROM
(
    SELECT A.Num NUM1, B.Num NUM2, C.Num NUM3 
    FROM 
    F0216 A, F0216 B, F0216 C
    WHERE A.Num + B.Num + C.Num = 10 
        AND A.Num != B.Num
        AND A.Num != C.Num
        AND B.Num != C.Num
    UNION ALL
    SELECT A.Num NUM1, B.Num NUM2, NULL -- NULL 为了和前面保持一致
    FROM 
    F0216 A, F0216 B
    WHERE A.Num + B.Num = 10 
        AND A.Num != B.Num
) A;