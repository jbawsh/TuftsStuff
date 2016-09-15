;; James McCants
;;
;; Comp105
;; hw4 - solver-tests.scm


;; This test case is important because it checks the 'not' functionality
;; and nested operators.
(val f1 '(or (and (not x) (not y) (not z)) z))
(val s1 '((x #f) (y #f) (z #f)))

;; This test case is important because it tests for no solution
(val f2 '(and (and x (not y)) (and y (not x))))
(val s2 'no-solution)

;; This test case is important because it tests De-Morgan's law
(val f3 '(not (and x y)))
(val s3 '((x #t) (y #f)))