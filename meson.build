project('ray-tac-toe', 'c',
  default_options: [
    'prefix=/home/noradenshi/Projects/ray-tac-toe',
    'c_std=c2x'
  ]
)

cc = meson.get_compiler('c')

deps = [
  #  dependency('gl'),
  #  cc.find_library('m', required: false),
  cc.find_library('raylib')
]

sources = files(
  'src/main.c',
  'src/grid.c',
  'src/restart.c'
) 

executable('exe', sources,
  include_directories: ['include'],
  dependencies: deps,
  install: true)
