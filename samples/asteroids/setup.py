from setuptools import setup

setup(
    name="asteroids",
    options = {
        'build_apps': {
            'copy_paths': ['.'],
            'exclude_paths': ['build/*', 'setup.py', 'requirements.txt', 'wheels/*', '*.swp'],
            'gui_apps': {
                'asteroids': 'main.py',
            },
            'plugins': [
                'pandagl',
            ],
            'deploy_platforms': [
                'manylinux1_x86_64',
                'macosx_10_6_x86_64',
                'win32',
                'win_amd64',
            ],
        }
    }
)