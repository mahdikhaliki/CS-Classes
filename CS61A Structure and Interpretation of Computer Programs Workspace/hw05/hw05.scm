;;;;;;;;;;;;;;;
;; Questions ;;
;;;;;;;;;;;;;;;

; Mutable functions in Scheme

(define (make-fib)
  (define curr 0) (define next 1)
  (define (next-fib) 
  	(define temp curr) 
  	(set! curr next) 
  	(set! next (+ temp next))
  	temp)
  next-fib
)