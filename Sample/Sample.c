#include "mm_jsapi.h"

/* Every implementation of a Javascript function must have this signature */
JSBool
computeSum(JSContext *cx, JSObject *obj, unsigned int argc, jsval *argv, jsval *rval)
{
	long a = 0, b = 0, sum;

	/* Make sure the right number of arguments were passed in */
	if (argc != 2)
		return JS_FALSE;

	/* Convert the two arguments from jsvals to longs */
	if (JS_ValueToInteger(cx, argv[0], &a) == JS_FALSE ||
		JS_ValueToInteger(cx, argv[1], &b) == JS_FALSE)
		return JS_FALSE;

	/* Perform the actual work */
	sum = a + b;

	/* Package the return value as a jsval */
	*rval = JS_IntegerToValue(sum);

	/* Indicate success */
	return JS_TRUE;
}

/* MM_STATE is a macro that expands to some definitions that are
 * needed in order interact with Animate. This macro must be defined
 * exactly once in your library */
MM_STATE

/* Animate calls MM_Init when your library is loaded. */
void
MM_Init()
{
	/* Declare the Javascript function, giving it a name that's
	 * likely to be unique */
	JS_DefineFunction(u"computeSum", computeSum, 2);
}
