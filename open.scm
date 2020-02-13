#! /bin/sh
exec guile --no-auto-compile -e main -s "$0" "$@"
!#

(use-modules (oop goops)
	     (g-golf))

(default-duplicate-binding-handler
  '(merge-generics replace warn-override-core warn last))

(eval-when (expand load eval)
  (gi-import-by-name "Gtk" "Appplication")
  (gi-import-by-name "Gtk" "ApplicationWindow"))

(define (main args)
  (let)
  )
