#include "ProcessBar.h"

#if PY_MAJOR_VERSION >= 3
#define PY3K
#endif

/*=========================封装调用=========================*/
static PyObject *Py_ProcessBar(PyObject *self, PyObject *args)
{
    float percent;
    char string[50];
    int ret;

    if (!PyArg_ParseTuple(args, "f|s", &percent, string))
    {
        //解析参数失败
        return NULL;
    }

    ret = Update(percent, string);
    return Py_BuildValue("i", ret);
}

/*========================功能实现========================*/
int Update(float percent, char string[])
{
    /*====Auto adjust size====*/
    struct winsize window;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &window);
    int bar_length = window.ws_col - 12;
    /*========================*/
    printf("\033[2K\r"); // clean current line
    printf("%s\n", string);
    printf("|");
    for (int i = 0; i < bar_length; i++)
    {
        if (i < percent / 100 * bar_length)
        {
            printf("█");
        }
        else
        {
            printf(" ");
        }
    }
    printf("| [%.1f%%]", percent);
    if (percent < 100)
    {
        printf("\033[1A");
    }
    fflush(stdout);
    return 0;
}

/*======================模块方法列表======================*/
static PyMethodDef Methods[] = {
    {"Update",      //调用名称
     Py_ProcessBar, //封装函数
     METH_VARARGS,  //解析
     "Show log"},
    {NULL, NULL, 0, NULL}};

/*=======================初始化函数=======================*/
#ifdef PY3K
static struct PyModuleDef ProcessBarModule = {
    PyModuleDef_HEAD_INIT,
    "ProcessBar",
    NULL,
    -1,
    Methods};

PyMODINIT_FUNC PyInit_ProcessBar(void)
{
    return PyModule_Create(&ProcessBarModule);
}
#endif
