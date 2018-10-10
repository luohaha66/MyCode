import logging
from logging.config import fileConfig

if __name__ == '__main__':
    fileConfig('logConfig.ini')
    logger = logging.getLogger()
    logger.debug('often makes a very good meal of %s', 'visiting tourists')