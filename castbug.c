#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_castbug.h"

zend_class_entry     *castbug_ce;
zend_object_handlers  castbug_handlers;


static int castbug_cast(zval *readobj, zval *retval, int type TSRMLS_DC)
{
    if (type == IS_LONG) {
        ZVAL_LONG(retval, 123);
        return SUCCESS;
    }
    else if (type == IS_DOUBLE) {
        ZVAL_DOUBLE(retval, 31.41);
        return SUCCESS;
    }
    else {
        return FAILURE;
    }
}


static zend_object *castbug_create_object(zend_class_entry *ce TSRMLS_DC)
{
    size_t size = sizeof(zend_object) + zend_object_properties_size(ce);
    zend_object *std = ecalloc(1, size);
    zend_object_std_init(std, ce TSRMLS_CC);
    std->handlers = &castbug_handlers;
    return std;
}


const zend_function_entry castbug_methods[] = {
    PHP_FE_END
};

static PHP_MINIT_FUNCTION(castbug)
{
    zend_class_entry ce;

    INIT_CLASS_ENTRY(ce, "CastBug", castbug_methods);
    castbug_ce = zend_register_internal_class(&ce TSRMLS_CC);
    castbug_ce->create_object = castbug_create_object;

    memcpy(&castbug_handlers, zend_get_std_object_handlers(),
           sizeof(zend_object_handlers));

    castbug_handlers.cast_object = castbug_cast;

    return SUCCESS;
}


const zend_function_entry castbug_functions[] = {
    PHP_FE_END
};

zend_module_entry castbug_module_entry = {
    STANDARD_MODULE_HEADER,
    PHP_CASTBUG_EXTNAME,
    castbug_functions,
    PHP_MINIT(castbug),
    NULL,
    NULL,
    NULL,
    NULL,
    PHP_CASTBUG_VERSION,
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_CASTBUG
ZEND_GET_MODULE(castbug)
#endif
