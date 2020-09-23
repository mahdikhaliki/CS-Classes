; The Curly Brackets

;1
; all-but-last takes in a list as its argument and returns the list without the last element
;
; Parameters(list)
; Return(list)
(define (all-but-last l)
  ; if the next element in the list is an empty list return an empty list
  ; else return the current element and what we get from all-but-last (cdr l)
  (if (null? (cdr l)) 
      '()
      (cons (car l) (all-but-last (cdr l)))))
"Problem 1"
(all-but-last '(hello))
(all-but-last '(go spartans))
(all-but-last '(i was just guessing at numbers and figures pulling the puzzles apart))

;2
; common? takes in two lists as its arguments and returns #t if the lists
; have at least one element in common and #f otherwise
;
; Parameters(list list)
; Return(boolean)
(define (member? x xs)
  (cond ((null? xs) #f)                 ;if the list is null return false
        ((equal? x (car xs)) #t)        ;else if the first element of the list = x return true
        (else (member? x (cdr xs)))))   ;else call member? again with the rest of the list

(define (common? l1 l2)
  (cond ((null? l1) #f)                 ;if l1 is empty return false
        ((null? l2) #f)                 ;else if l2 is empty return false
        ((member? (car l1) l2) #t)      ;else if the first element of l1 is a member of l2 return true
        (else (common? (cdr l1) l2))))  ;else return common? with the rest of l1 and all of l2

"Problem 2"
(common? '(go spartans) '(1 2 3))
(common? '(they had to go) '(go spartans))
(common? '(0 0 0 5 9) '(a  b 3 4 5 6))
(common? '(1 2 3) '())
(common? '() '(1 2 3))
(common? '() '())

;3
; make-list takes in three integers as its arguments (start, stop and step). The  function returns a list
; of integers from start to stop (including start but not including  stop) separated by step.
;
; Parameters(int int int)
; Return(list)
(define (make-list x y s)
  ;if x >= y then return an empty list, else make a new list with x and make-list (x+s) y s
  (if (>= x y)
      '()
      (cons x (make-list (+ x s) y s))))

"Problem 3"
(make-list 2 10 2)
(make-list -3 10 3)
(make-list 5 5 3)
(make-list 5 1 2)

;4
; mix takes two lists, and returns a new list formed by alternating the elements of both lists. If one of
; the lists is longer than the other, the extra elements of the longer list are included at the end of the new list
;
; Parameters(list list)
; Return(list)
(define (mix l1 l2)
  ; if l1 is null and l2 is null return an empty list
  ;     if l1 is null and l2 is not null return new list with the first element of l2 and mix l1 (cdr l2)
  ; else if l1 is not null and l2 is null return new list with first lement of l1 and mix (cdr l1) l2
  ; else return a list with the first element of l1, first element of l2, and mix (cdr l1) (cdr l2)
  (cond ((null? l1)
           (if (null? l2)
              '()
              (cons (car l2) (mix l1 (cdr l2)))))
        ((null? l2) (cons (car l1) (mix (cdr l1) l2)))
        (else (cons (car l1) (cons (car l2) (mix (cdr l1) (cdr l2)))))))

"Problem 4"
(mix '(1 2 3) '(a b c d e))
(mix '(1 2 3 4 5) '(a b))
(mix '(1 2 3) '(a b c))
(mix '(1 2 3) '())
(mix '() '(1 2 3))
(mix '() '())

;5
; take-while takes a predicate (a function) and a list  as arguments.  The function returns a new list that
; contains the first few elements of the input list that meet the criteria specified by the predicate.
; The first element that does not meet the criteria and all subsequent elements are excluded.
;
; Parameters(function list)
; Return(list)
(define (take-while f l)
  (if (null? l)                                   ; if the list is empty return an empty list
      '()                              
      (if (f (car l))                             ; else if the predicate returns true return
          (cons (car l) (take-while f (cdr l)))   ; a new list with the first element of l and take-while f (cdr l)
          '())))                                  ; else return an empty list

"Problem 5"
(take-while (lambda (x) ( > x 3 )) '(9 4 2 3 7 8 6))
(take-while (lambda (x) ( > x 5 )) '(4 2 3 7 8 6))
(take-while (lambda (x) ( = x 5 )) '())
(take-while (lambda (x) ( = x 5 )) '(5 5 5 5 3))
(take-while (lambda (x) ( > x 1 )) '(4 2 3 7 8 6))
(take-while (lambda (x) ( > x 1 )) '())

;6
; at-least-two? takes a list of numbers as its argument.The function returns #t if the numbers
; are in order with a difference of at least two between two consecutive numbers.
;
; Parameters(list)
; Return(boolean)
(define (at-least-two? l)
  ; if the list is empty return true, else check other conditions
  (if (null? l)
      #t
      ; if list is not empty and the next element is null return true
      ; else if l[1] - l[0] is >= 2 call at-least-two with l[1...n]
      ; else return false
      (cond ((null? (cdr l)) #t)
            ((>= (- (cadr l) (car l)) 2) (at-least-two? (cdr l)))
            (else #f))))

"Problem 6"
(at-least-two? '(2 5 7 20))
(at-least-two? '(5 2 7 20))
(at-least-two? '(2 5 6 20))
(at-least-two? '())
(at-least-two? '(4))
(at-least-two? '(-4 -2 0 6 20))

;7
; lowest-helper takes a list  of numbers as its argument. The function returns the lowest number in the list.
;
; Parameters(list)
; Return(int)
(define (lowest l)
  (lowest-helper (cdr l) (car l))) ;return the value from the lowest-helper, assume l[0] is the lowest initial number
  
(define (lowest-helper l lowest_num)
  ; if the list is empty return the lowest_num seen
  ; else if l[0] is less than lowest_num, call lowest-helper with (cdr l) (car l)
  ; else call lowest-helper with (cdr l) lowest_num
  (cond ((null? l) lowest_num)
        ((< (car l) lowest_num) (lowest-helper (cdr l) (car l)))
        (else (lowest-helper (cdr l) lowest_num))))

"Problem 7"
(lowest '(4 1 -9 2 10 -3))
(lowest '(4 1 0 2 10 -3))
(lowest '(-21 1 -9 2 10 -3))
(lowest '(100))
