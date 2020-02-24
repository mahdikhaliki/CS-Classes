;;;;;;;;;;;;;;;
;; Questions ;;
;;;;;;;;;;;;;;;

; Streams

(define (find s predicate)
  (cond 
    ((null? s) #f)
    ((predicate (car s)) (car s))
    (else (find (cdr-stream s) predicate))
  )
)

(define (scale-stream s k)
  (cond 
    ((null? s) nil)
    ((cons-stream (* (car s) k) (scale-stream (cdr-stream s) k)))
  )
)

(define (has-cycle? s)
  (define (pair-tracker seen-so-far curr)
    (cond ((null? curr) #f)
          ((contains?  seen-so-far curr) #t)
          (else (pair-tracker (cons curr seen-so-far) (cdr-stream curr))))
    )
  (pair-tracker nil s)
)

(define (contains? lst s)
  (cond
    ((null? lst) #f)
    ((eq? (car lst) s) #t)
    (else (contains? (cdr lst) s))
  )
)
(define (has-cycle-constant s)
  'YOUR-CODE-HERE
)

; Tail recursion

(define (accumulate combiner start n term)
  (if (= n 0) start (accumulate combiner (combiner start (term n)) (- n 1) term))
)

; Macros

(define-macro (list-of expr for var in lst if filter-expr)
  (list 'map (list 'lambda (list var) expr) (list 'filter (list 'lambda (list var) filter-expr) lst)))
)