# -*- coding: utf-8 -*-
"""
基础native方法收集器, 完成c/c++native方法收集, 并整合到对应的脚本语言中
"""

import re
from os import path as op

from cpputils import *

from com.cfg import cfg
from com.defs import LangType
from com.log import Log


class BaseNativeMethodCollector(object):
    def __init__(self, proj_name, search_path, classname_base=None, filename_base=None):
        self.search_path = search_path
        self.proj_name = proj_name
        self.search_base = op.basename(search_path).capitalize()

        if classname_base is not None:
            self.classname_base = classname_base
        else:
            self.classname_base = self.search_base

        if filename_base is not None:
            self.filename_base = filename_base
        else:
            self.filename_base = self.search_base

    def build(self):
        """构建方法文件"""
        raise NotImplementedError()

    def _buildable(self):
        if not op.exists(self.search_path):
            Log.fi('Path [{0}] not found, skip build methods...', self.search_path)
            return False

        return True

    @staticmethod
    def _build_filematch_re():
        return re.compile(r'(_[a-zA-Z]+)+\.h')

    def _build_cpp_cls_name(self):
        return '{0}_{1}Methods'.format(self.proj_name, self.classname_base)

    def _build_cpp_file(self):
        cpp_file_path = op.join(self.search_path, '_{0}Methods.h'.format(self.filename_base))
        cpp_file = CppFile(
            cpp_file_path,
            author=cfg.author_and_email,
            ver=cfg.ver,
            include_macro_prefix=self.proj_name.upper())
        cpp_file.custom_filehead = cfg.gen_file_license_head(LangType.cplusplus) + \
            '\n// !!! This file is auto generated by script tool, do not modify it!!!\n'
        cpp_file.addincl('{0}/common/LibHeader.h'.format(self.proj_name))
        cpp_file.addincl('{0}/common/Macro.h'.format(self.proj_name))
        return cpp_file
