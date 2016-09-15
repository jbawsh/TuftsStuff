;;James McCants
;;
;;solution.scm
;;
;;Comp105 - uscheme - hw3
;;10/7/15


;;2.a
;;
;;Returns the number of top-level elements in xs that are equal to x
(define count (x xs)
  (if (null? xs) 
      0
      (if (equal? x (car xs))
          (+ 1 (count x (cdr xs)))
          (+ 0 (count x (cdr xs))))))


;;checks for functionality of top-level elements
(check-expect (count 'a '(1 b a (c a))) 1)
;;checks to see if empty lists work
(check-expect (count '() '(() a ())) 2)


;;2.b
;;
;;Returns the total number of elements in xs that are equal to x, not just
;;top-level elements
(define countall (x xs)
  (if (null? xs) 
      0
      (if (equal? x (car xs))
          (+ 1 (countall x (cdr xs)))
          (if (atom? (car xs))
              (+ 0 (countall x (cdr xs)))
              (+ 0 (countall x (car xs)))))))


;;checks to see if it goes into elements
(check-expect (countall 'a '(1 b a (c a))) 2)
;;checks to see if empty lists work
(check-expect (countall '() '(1 b () a (() ()))) 3)


;;2.c
;;
;;Returns a list in which every list in xs is recursively mirrored, and the
;;resulting lists are in reverse order - see pg.170 2.(c)
(define mirror (xs)
  (if (null? xs)
      xs
      (if (atom? (car xs))
          (append (mirror (cdr xs)) (list1 (car xs)))
          (append (mirror (cdr xs)) (list1 (mirror (car xs)))))))


;;Basic check for functionality
(check-expect (mirror '(1 2 3 4 5)) '(5 4 3 2 1))
;;Checks for proper in element mirroring
(check-expect (mirror '((a (b 5)) (c d) e)) '(e (d c) ((5 b) a)))


;;2.d
;;
;;Returns the list xs with all internal parens removed
(define flatten (xs)
  (if (null? xs)
      xs
      (if (atom? xs)
          (list1 xs)
          (append (flatten (car xs)) (flatten (cdr xs))))))


;;Checks for multiple layers of flattening
(check-expect (flatten '((I (Ching Kong)) (U Thant))) '(I Ching Kong U Thant))
;;Checks for flattening with nested lists
(check-expect (flatten '((((a))))) '(a))
;;Checks with empty list
(check-expect (flatten '(() (a b (c)))) '(a b c))


;;2.e
;;
;;Returns true if the first len(xs) elements of ys are equal to xs
(define same-vals? (xs ys)
  (if (null? xs)
      #t
      (if (equal? (car xs) (car ys))
          (same-vals? (cdr xs) (cdr ys))
          #f)))

;;Returns true if xs is a contiguous sublist of ys
(define contig-sublist? (xs ys)
  (if (equal? (car xs) (car ys))
      (same-vals? xs ys)
      (contig-sublist? xs (cdr ys))))


;;Checks for sublist but not contig
(check-expect (contig-sublist? '(a b c) '(x a y b z c)) #f)
;;Checks nested lists
(check-expect (contig-sublist? '((a b)) '((a b) b)) #t)


;;2.f
;;
;;Returns true if the list xs is a mathematical subsequence of the list ys
(define sublist? (xs ys)
  (if (null? xs)
      #t
      (if (null? ys)
          #f
          (if (equal? (car xs) (car ys))
              (sublist? (cdr xs) (cdr ys))
              (sublist? xs (cdr ys))))))


;;Checks for spread out sublist
(check-expect (sublist? '(a c e) '(a b c d e)) #t)
;;Checks wrong order
(check-expect (sublist? '(a b c) '(c b a)) #f)


;;6
;;
;;Returns true if x is an even number
(define even? (x) (= (mod x 2) 0))

;;Returns the longest prefix of xs where every element of xs satisfies pre?
(define takewhile (pre? xs)
  (if (pre? (car xs))
      (cons (car xs) (takewhile pre? (cdr xs)))
      '()))

;;Removes the longest prefix of xs where every element of xs satisfies pre?
;;and returns whatever is left over
(define dropwhile (pre? xs)
  (if (pre? (car xs))
      (dropwhile pre? (cdr xs))
      (append xs '())))


;;Checks for correct taking spot
(check-expect (takewhile even? '(2 4 6 7 8 9)) '(2 4 6))
;;Checks for correct droping spot
(check-expect (dropwhile even? '(2 4 6 7 8 9)) '(7 8 9))


;;15
;;
;;The function uses let to set the meaning of + to * and the meaning of * to +.
;;Let creates locally bound variables whose values have no effect on one another
;;so both declarations are independent of eachother. The final line is basically
;;(sqrt (+ (* x x) (* y y))).


;;A
;;
;;Returns the longest prefix of xs that contains at most n elements
(define take (n xs)
  (if (!= n 0)
      (if (null? xs)
          xs
          (cons (car xs) (take (- n 1) (cdr xs))))
      '()))

;;Removes up to n elements from the front of xs and returns whatever is left
;;over
(define drop (n xs)
  (if (!= n 0)
      (if (null? xs)
          xs
          (drop (- n 1) (cdr xs)))
      (append xs '())))


;;Checks for full length prefix in take
(check-expect (take 3 '(a b c d e f)) '(a b c))
;;Checks for less than full length in take
(check-expect (take 5 '(a b c)) '(a b c))
;;Checks for full length drop
(check-expect (drop 3 '(a b c d e f)) '(d e f))
;;Checks for more than full drop
(check-expect (drop 5 '(a b c)) '())


;;B
;;
;;Returns an association list made out of lists xs and ys
(define zip (xs ys)
  (if (null? xs)
      xs
      (cons (list2 (car xs) (car ys)) (zip (cdr xs) (cdr ys)))))

;;Returns the first list out of the association list xs
(define build-one (xs)
  (if (null? xs)
      xs
      (cons (caar xs) (build-one (cdr xs)))))

;;Returns the second list out of the association list xs
(define build-two (xs)
  (if (null? xs)
      xs
      (cons (cadar xs) (build-two (cdr xs)))))

;;Returns a pair of lists parsed from the association list xs
(define unzip (xs)
  (if (null? xs)
      xs      (list2 (build-one xs) (build-two xs))))


;;Checks for correct formatting of zip
(check-expect (zip '(1 2 3) '(a b c)) '((1 a) (2 b) (3 c)))
;;Checks for correct formatting of unzip
(check-expect (unzip '((I Magnin) (U Thant))) '((I U) (Magnin Thant)))


;;C
;;
;;Returns a^2
(define square (a) (* a a))

;;Returns 1000/a
(define invert (a) (/ 1000 a))

;;Returns the element of a for which (f a) is largest
(define arg-max (f a)
  (if (null? a)
      1
      (if (> (f (car a)) (f (arg-max f (cdr a))))
          (car a)
          (arg-max f (cdr a)))))


;;Checks for correctness if first arg is correct
(check-expect (arg-max square '(5 4 3 2 1)) 5)
;;Checks for correctness if last arg is correct
(check-expect (arg-max invert '(5 4 3 2 1)) 1)


;;D
;;
;;Accepts a graph in edge-list representation and returns a representation of 
;;the same graph in successors-map representation. Actually just returns because
;;I didn't get it working.
(define successors-map-of-edge-list (xs) xs)

;;Accepts a graph in successors-map representation and returns a representation
;;of the same graph in edge-list representation. Actually just returns because I
;;didn't get it working.
(define edge-list-of-successors-map (xs) xs)


;;E
;;
;;Returns a single sorted list the same length as xs and ys together
(define merge (xs ys)
  (if (null? xs)
      (append ys '())
      (if (null? ys)
          (append xs '())
          (if (> (car xs) (car ys))
              (cons (car ys) (merge (cdr ys) xs))
              (cons (car xs) (merge (cdr xs) ys))))))


;;Checks for corrct length and sorting
(check-expect (merge '(1 2 3) '(4 5 6)) '(1 2 3 4 5 6))
;;Checks for correct length and back and forth sorting
(check-expect (merge '(1 3 5) '(2 4 6)) '(1 2 3 4 5 6))
;;Checks for varying lengths and duplicates
(check-expect (merge '(1 2) '(1 2 3)) '(1 1 2 2 3))


;;F
;;
;;Returns a single list of alternating elements from lists xs and ys until one
;;ends and then the rest of the second list is appended on
(define interleave (xs ys)
  (if (null? xs)
      (append ys '())
      (if (null? ys)
          (append xs '())
          (cons (car xs) (cons (car ys) (interleave (cdr xs) (cdr ys)))))))


;;Checks lists of same length
(check-expect (interleave '(1 2 3) '(a b c)) '(1 a 2 b 3 c))
;;Checks when xs is shorter
(check-expect (interleave '(1 2 3) '(a b c d e f)) '(1 a 2 b 3 c d e f))
;;Checks when ys is shorter
(check-expect (interleave '(1 2 3 4 5 6) '(a b c)) '(1 a 2 b 3 c 4 5 6))
;;Checks nested lists
(check-expect (interleave '(() (a b) (1 2)) '(())) '(() () (a b) (1 2)))