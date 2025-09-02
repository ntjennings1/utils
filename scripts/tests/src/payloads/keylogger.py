""" Native imports. """
from pynput import keyboard

""" Callback function that prints keystroke.

@param key : System logged keystroke
@type key : keyboard.key
"""
def on_press(key):
    print(f"Key pressed: {key}")

""" Establishes a key logging system.

@return null
"""
def main():
    with keyboard.Listener(on_press=on_press) as listener:
        listener.join()
        
""" Runs the main function.

@return null
"""
if __name__ == "__main__":
    main()