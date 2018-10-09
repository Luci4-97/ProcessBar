from distutils.core import setup, Extension

MOD = 'ProcessBar'
setup(
    name=MOD,
    version = '1.0',
    ext_modules=[
        Extension(
            MOD,
            sources=['ProcessBar.c'],
            include_dirs=[
                "/Library/Frameworks/Python.framework/Versions/3.6/include/python3.6m/"],
            language="c")])
