import subprocess
import random

def run_game():
    # Compile the C++ program
    compile_process = subprocess.run(['g++', '-o', 'card_game', 'card_game.cpp'], capture_output=True, text=True)
    if compile_process.returncode != 0:
        print("Compilation failed:")
        print(compile_process.stderr)
        return

    success_message = "You passed the game!"
    game_passed = False

    while not game_passed:
        # Run the compiled game
        process = subprocess.Popen(['./card_game'], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

        try:
            while True:
                # Read the game's output
                output = process.stdout.readline()
                if not output:
                    break
                print(output.strip())

                # Check for success message
                if success_message in output:
                    game_passed = True
                    print("Game successfully passed!")
                    break

                # Make a random guess (yes or no)
                if "yes/no" in output:
                    guess = random.choice(["yes", "no"])
                    print(f"Guessing: {guess}")
                    process.stdin.write(guess + "\n")
                    process.stdin.flush()

        except Exception as e:
            print(f"An error occurred: {e}")
        finally:
            process.terminate()

if __name__ == "__main__":
    run_game()