import os
import sys
import subprocess
import logging

logger = logging.getLogger(__name__)
logging.basicConfig(level=logging.DEBUG)

logger.info("Installing conan")
subprocess.run([sys.executable, "-m", 'pip', 'install', "conan"], check=True)

build_type = ["Release", "Debug"]

for type in build_type:
  logger.info("Starting build ${type}")
  subprocess.run(['conan', 'build', ".", "-s", "build_type=${type}", "-c", "tools.build:skip_test=False", "-pr:a=./ci/src/conan-profile/profile-release-gcc-13-x86_64", "--build='*'"], check=True)

