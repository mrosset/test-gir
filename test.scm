#! /bin/sh
exec guile -e main -s "$0" "$@"
!#

(use-modules (g-golf))

(define (main args)
  (g-irepository-require "Clutter")
  (let* ((info (g-irepository-find-by-name "Clutter" "PaintNode"))
	 (type (g-registered-type-info-get-g-type info)))
   (format #t "~a\n" (g-type-name type))))
