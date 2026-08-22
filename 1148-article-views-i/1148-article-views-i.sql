-- Write your PostgreSQL query statement below
SELECT DISTINCT author_id AS id
From Views
where author_id = viewer_id
ORDER BY id;