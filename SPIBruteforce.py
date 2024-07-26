import subprocess
import random

class SPIBruteforce:
    def __init__ (self) -> None:
        self.__alphabet: str = "ABCDEF012346789";

    def start (self, lenght: int, USBPort: str) -> str:
        while (True):
            key: str = "".join(random.choices(self.__alphabet, k=lenght));
            with open("key.txt", "w") as file:
                file.write(key);
            result = subprocess.run(["spiunlock.exe", "unlock", "key.txt", "-usb", USBPort], capture_output=True, text=True);
            if ("ERROR" in result.stdout):
                print("KEY ----> %s IS WRONG" % (key,));
            else:
                print("KEY ----> %s UNLOCKING THE CHIP" % (key,));
                return key;

if (__name__ == "__main__"):
    port: str = input("Enter USB Port >>> );
    unit = SPIBruteforce();
    print("\n\n" + unit.start(32, port));
