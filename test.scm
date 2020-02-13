#! /bin/sh
exec guile --no-auto-compile -e main -s "$0" "$@"
!#

(use-modules (oop goops)
             (g-golf))

(default-duplicate-binding-handler
  '(merge-generics replace warn-override-core warn last))

(eval-when (expand load eval)
  (gi-import-by-name "Gtk" "init")
  (gi-import-by-name "Gtk" "main")
  (gi-import-by-name "Gtk" "main_quit")
  (gi-import-by-name "Gtk" "Window")
  (gi-import-by-name "Gtk" "Widget"))

(define (main args)
  (for-each (lambda (namespace)
              (format #t "~a\n" namespace)
              (dimfi "  lib: " (g-irepository-get-shared-library namespace))
              (dimfi "  path: " (g-irepository-get-typelib-path namespace))
              (dimfi "  version: " (g-irepository-get-version namespace))
              (format #t "\n"))
            (g-irepository-get-loaded-namespaces))

  (gtk-init #f #f)

  (let ((window (make <gtk-window>)))
    (connect window 'destroy (lambda _
                               (gtk-main-quit)))
    (gtk-widget-show-all window))
  (gtk-main))


  ;; (let* ((info (g-irepository-find-by-name "Clutter" "PaintNode"))
  ;;        (type (g-registered-type-info-get-g-type info))
  ;;        (name (g-type-name type)))
  ;;   (unless name
  ;;     (error (format #f "type name for ClutterPaintNode is ~a" name)))

  ;;   (dimfi "base-info: " (g-irepository-find-by-gtype type))
  ;;   (dimfi "type-name: " name)
  ;;   #t)

;; Local Variables:
;; mode: scheme
;; End:
