#ifndef CASTBUG_H
#define CASTBUG_H

#define PHP_CASTBUG_VERSION "1.0.0"
#define PHP_CASTBUG_EXTNAME "castbug"

extern zend_class_entry *castbug_ce;
extern zend_module_entry castbug_module_entry;
#define phpext_castbug_ptr &castbug_module_entry

#endif
