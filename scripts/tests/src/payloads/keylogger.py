from pynput import keyboard

def on_press(key):
    print(f"Key pressed: {key}")
    
def main():
    with keyboard.Listener(on_press=on_press) as listener:
        listener.join()
    
if __name__ == "__main__":
    main()