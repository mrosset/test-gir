#! /bin/sh
exec guile -e main -s "$0" "$@"
!#

(use-modules (g-golf))

(define (main args)
  (g-irepository-require "Clutter")

  (let* ((info (g-irepository-find-by-name "Clutter" "PaintNode"))
	 (type (g-registered-type-info-get-g-type info))
	 (name (g-type-name type)))

    (unless name
      (error "could not get type name for ClutterPaintNode"))
    (dimfi "base-info: " (g-irepository-find-by-gtype type))
    (dimfi "type-name: " name)

    (for-each (lambda (namespace)
		(dimfi namespace)
		(dimfi "  path: " (g-irepository-get-typelib-path namespace))
		(dimfi "  shared lib: " (g-irepository-get-shared-library namespace))
		(dimfi "  version: " (g-irepository-get-version namespace)))
	      '("Clutter" "GLib"  "GObject"))))


;; Local Variables:
;; mode: scheme
;; End:
