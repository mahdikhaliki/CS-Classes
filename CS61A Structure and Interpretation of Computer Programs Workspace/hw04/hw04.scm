; Q1
(define (sign x)
  (cond ((< x 0) -1) ((= x 0) 0) (else 1))
)

; Q2
(define (square x) (* x x))

(define (pow b n)
  (cond ((= n 1) b)
        ((even? n) (square (pow b (/ n 2))))
        (else (* b (square (pow b (/ (- n 1) 2))))))
)

; Q3
(define (cddr s)
  (cdr (cdr s)))

(define (cadr s)
  (car (cdr s))
)

(define (caddr s)
  (car (cddr s))
)

; Q4
(define (ordered? s)
  (cond ((equal? (null? (cdr s)) #t) #t)
        ((> (car s) (car (cdr s))) #f)
        (else (ordered? (cdr s)))
  )
)

; Q5
(define (nodots s)
  (cond
    ((null? s) nil)
    ((number? s) (cons s nil))
    ((null? (cdr s)) s)
    ((pair? (car s)) (cons (nodots (car s)) (nodots (cdr s))))
    ((not (pair? (cdr s))) (cons (car s) (cons (cdr s) nil)))
    (else (cons (car s) (nodots (cdr s))))
  )
)

; Q6
(define (empty? s) (null? s))

(define (add s v)
  (cond ((empty? s) (list v))
        ((< v (car s)) (cons v s))
        ((equal? v (car s)) s)
        (else (cons (car s) (add (cdr s) v)))
  )
)

; Q7
; Sets as sorted lists
(define (contains? s v)
  (cond ((empty? s) #f)
        ((equal? (car s) v) #t)
        (else (contains? (cdr s) v))
  )
)

; Q8
(define (intersect s t)
  (cond ((or (empty? s) (empty? t)) (list))
        ((equal? (car s) (car t)) (cons (car s) (intersect (cdr s) (cdr t))))
        ((> (car s) (car t)) (intersect s (cdr t)))
        (else (intersect (cdr s) t))
  )
)

(define (union s t)
  (cond ((empty? s) t)
        ((empty? t) s)
        ((equal? (car s) (car t)) (cons (car s) (union (cdr s) (cdr t))))
        ((< (car s) (car t)) (cons (car s) (union (cdr s) t)))
        (else (cons (car t) (union s (cdr t))))
  )    
)