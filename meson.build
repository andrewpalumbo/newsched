# SPDX-FileCopyrightText: 2020 Josh Morman 
#

project('newsched', 'cpp', 
  version : '0.0.0',
  license : 'GPLv3',
  default_options : ['cpp_std=c++17'])

cc = meson.get_compiler('cpp')
rt_dep = cc.find_library('rt', required : false)

cuda_available = add_languages('cuda', required : false)

boost_dep = dependency('boost', modules : ['program_options'], version : '>=1.65')
volk_dep = dependency('volk', version : '>=2.2')
yaml_dep = dependency('yaml-cpp', version : '>=0.6')
spdlog_dep = dependency('spdlog')
threads_dep = dependency('threads')
fmt_dep = dependency('fmt')
gtest_dep = dependency('gtest', main : true, version : '>=1.10', required : get_option('enable_testing'))
cuda_dep = dependency('cuda', version : '>=10.1', required : cuda_available and get_option('enable_cuda'))

subdir('runtime')
subdir('blocklib')
subdir('schedulers')
subdir('docs')
