import os
import sys
import google.generativeai as genai 


"""Start the GEMINI API"""
try:
    api_key = os.getenv("GEMINI_API_KEY")
    if not api_key:
        raise ValueError("Environment variable GEMINI_API_KEY not found")

    genai.configure(api_key=api_key)
except Exception as e:
    print(f"Error configuring Gemini client: {e}")
    print("Please, set up the API_KEY before running the script.")
    sys.exit(1)

def geminiAsker(prompt: str, model_name: str = "gemini-1.5-flash") -> str:
    """Send a prompt to the generative model"""
    try:
        model = genai.GenerativeModel(model_name)
        response = model.generate_content(prompt)
        return response.text
    except Exception as e:
        print(f"Error: {e}")
        return "" 

def savetofile(content: str, filename: str = "response.txt"):
    """Save the prompt in a file"""
    with open(filename, 'a', encoding='utf-8') as f:
        f.write(content + "\n---\n")

def main():
    configure_api()

    prompt = 'Write a hello world program in python'
    
    content = geminiAsker(prompt)

    if content:
        print("--- Ouput from Gemini ---")
        print(content)
        print("--------------------------")
        savetofile(content, "response.txt")
        print(f"Ouput saved in '{filename}'.")


if __name__ == "__main__":
    main()