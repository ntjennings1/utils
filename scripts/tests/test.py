import asyncio
import subprocess
import os

async def run_command():
    os.system('ping -n 3 google.com')

def main():
    
    while True:
        asyncio.run(run_command())    

if __name__ == '__main__':
    main()