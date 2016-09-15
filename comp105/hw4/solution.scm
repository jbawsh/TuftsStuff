;; James McCants
;;
;; Comp 105
;; hw4 - uscheme higher order functions

;;
;; Problem A
;;

;;Uses a lambda to recursively simulate a while loop that modifies x until
;;(p x y) is satisfied and then returns (h x y)
(define f-functional (y) ; (x)
  (letrec ((x e)
           (check (lambda (x) (if (p x y)
                                  (check (g x y))
                                  (h x y)))))
           (check x)))

;;
;; Problem 10
;;

;;b
;;
;;Returns the largest element of xs
(define max* (xs)
  (foldr max
         (car xs)
         xs))
                            
(check-expect (max* '(1 2 3 4)) 4)

;;c
;;
;;Returns the greatest common divisor of all elements of xs
(define gcd* (xs)
  (foldr gcd
         0
         xs))

;;d
;;
;;Returns the least common multiple of all elements of xs
(define lcm* (xs)
  (foldr lcm
         1
         xs))

;;e
;;
;;Returns the sum of every element of xs added with one another
(define sum (xs)
  (foldr +
         0
         xs))

(check-expect (sum '(1 2 3)) 6)

;;f
;;
;;Returns the product of each element of xs multiplied with one another
(define product (xs)
  (foldr *
         1
         xs))

(check-expect (product '(1 2 3 4)) 24)

;;g
;;
;;Appends the list xs to the list ys and returns the result
(define append (xs ys)
  (foldr cons
         ys
         xs))

(check-expect (append '(1 2) '(3 4)) '(1 2 3 4))

;;i
;;
;;Returns the reverse of the list xs
(define reverse (xs)
  (foldl cons
         '()
         xs))

;;j
;;
;;Returns sorted xs via insertion sort
(define insertion-sort (xs)
  (foldr (letrec 
             ((insert (lambda (next rest)
                        (if (null? rest)
                            (list1 next)
                            (if (< next (car rest))
                                (cons next rest)
                                (cons (car rest) (insert next (cdr rest))))))))
           insert)     
         '()
         xs))

(check-expect (insertion-sort '(4 2 1)) '(1 2 4))
     
;;
;; Problem 11
;;                                      

;;Returns the length of xs using a lambda that counts up by 1 for each iteration
;;of foldr
(define length (xs)
  (foldr (lambda (next count) (let ((count (+ count 1))) count))
         0
         xs))

(check-expect (length '(1 2 3 4)) 4)
(check-expect (length '()) 0)


;;Returns xs with f called on every element
(define map (f xs)
  (foldr (lambda (next rest) (let ((next (f next))) (cons next rest)))
         '()
         xs))

(define add2 (x) (let ((x (+ x 2))) x))

(check-expect (map add2 '(1 2 3)) '(3 4 5))


;;Returns xs with everything that doesn't satisfy p? removed
(define filter (p? xs)
  (foldr (lambda (next rest) (let ((next (if (p? next)
                                             (cons next rest)
                                             rest))) next))
         '()
         xs))

(define even? (x) (= (mod x 2) 0))

(check-expect (filter even? '(1 10)) '(10))


;;Returns ture if there is any element in xs that satisfies p?, false otherwise
(define exists? (p? xs)
  (foldr (lambda (next rest) (let ((next (if (p? next)
                                             #t
                                             #f))) (or next rest)))
         #f
         xs))

(check-expect (exists? even? '()) #f)
(check-expect (exists? even? '(2 3 5)) #t)

(define all? (p? xs)
  (foldr (lambda (next rest) (let ((next (if (p? next)
                                             #t
                                             #f))) (and next rest)))
         #t
         xs))

(check-expect (all? even? '()) #t)
(check-expect (all? even? '(2 4 6)) #t)

;;
;; Problem 16
;;

;;a
;;
;;Returns a boolean set that contains x along with the original set
(define add-element (x s)
  (lambda (y) (or (equal? x y) (s y))))

;;Returns a boolean set the contains both original sets
(define union (s1 s2)
  (lambda (y) (or (s1 y) (s2 y))))

;;Returns a boolean set for values that return true for both s1 and s2
(define inter (s1 s2)
  (lambda (y) (and (s1 y) (s2 y))))

;;Returns a boolean set for values in s1 that are not in s2
(define diff (s1 s2)
  (lambda (y) (and (s1 y) (not (s2 y)))))

;;b
;;
;;Returns a list of functions for set operations with the eqfun of the user's
;;choosing built in
(define mk-set-ops (eqfun)
  (list6 (lambda (x) #f)                                            ;empty
         (lambda (x s) (s x))                                       ;mem
         (lambda (x s) (lambda (y) (or (eqfun x y) (s y))))         ;add-el
         (lambda (s1 s2) (lambda (y) (or (s1 y) (s2 y))))           ;union
         (lambda (s1 s2) (lambda (y) (and (s1 y) (s2 y))))          ;inter
         (lambda (s1 s2) (lambda (y) (and (s1 y) (not (s2 y)))))))  ;diff


;;
;; Problem 23
;;

;;Returns a list of boolean values for literals in a formula that satisfy
;;the formula as a logical expression
;;
;;make-formula extends cur that makes the single formula equal to bool
;;
;;make-all extends cur to find an assignment that makes all of the formulas
;;         equal to bool
;;
;;make-any extends cur to find an assignment that makes any of the formulas
;;         equal to bool
(define make-formula-true (f fail succ)
  (letrec ((make-formula (lambda (formula bool cur fail succeed)
                           (#f)))
           (make-all (lambda (formulas bool cur fail succeed)
                       (#f)))
           (make-any (lambda (fomulas bool cur fail succeed)
                       (#f))))
    (make-formula f #f '() #f #t)))