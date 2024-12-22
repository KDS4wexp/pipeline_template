import os
import sys
import subprocess
import logging

logger = logging.getLogger(__name__)
logging.basicConfig(level=logging.DEBUG)

logger.info("Installing conan")
subprocess.run([sys.executable, "-m", 'pip', 'install', "conan"], check=True)

logger.info("Starting build")
subprocess.run(['conan', 'build', "."], check=True)