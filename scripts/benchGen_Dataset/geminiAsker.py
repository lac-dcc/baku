import os
import sys
import google.generativeai as genai 

def configure_api():
    """Start the GEMINI API"""
    api_key = os.getenv("GEMINI_API_KEY")
    if not api_key:
        print("Erro: The GEMINI_API_KEY not founded.")
        print("Please, set up the API_KEY before the experiment.")
        sys.exit(1) 
    
    genai.configure(api_key=api_key)
    
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