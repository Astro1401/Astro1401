SELECT customer_id, COUNT(*) AS count_no_trans
FROM Visits
LEFT JOIN Transactions
using (visit_id)
WHERE Transactions.visit_id IS NULL
GROUP BY customer_id;