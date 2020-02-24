; Lab 13: Final Review

; Q2
(define (rle s)
  'YOUR-CODE-HERE
)

; Q2 testing functions
(define (list-to-stream lst)
    (if (null? lst) nil
                    (cons-stream (car lst) (list-to-stream (cdr lst))))
)

(define (stream-to-list s)
    (if (null? s) nil
                 (cons (car s) (stream-to-list (cdr-stream s))))
)

; Q3
(define (tail-replicate x n)
  'YOUR-CODE-HERE
)