((nil . ((eval . (progn
                   (make-local-variable 'auto-insert-alist)
                   (setq
                    auto-insert-alist
                    '((("\\.\\([Hh]\\|hh\\|hpp\\)\\'" . "C / C++ header") . [
                                                                             (lambda () (my/autoinsert-yas-expand "head"))])
                      (("\\.\\([C]\\|cc\\|cpp\\)\\'" . "C++ source") . [
                                                                        (lambda () (my/autoinsert-yas-expand "leetcode"))]))
                    ))
               ))))
