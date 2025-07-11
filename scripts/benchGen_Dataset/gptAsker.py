import os
import sys
from openai import OpenAI

"""Start the OPENAI Client"""
try:
    client = OpenAI(api_key=os.getenv("OPENAI_API_KEY"))
    if not os.getenv("OPENAI_API_KEY"):
        raise ValueError("Environment variable OPENAI_API_KEY not found.")
except Exception as e:
    print(f"Error configuring OpenAI client: {e}")
    print("Please, set up the API_KEY before running the script.")
    sys.exit(1)

def openaiAsker(prompt: str, model_name: str = "gpt-3.5-turbo") -> str:
    try:
        messages = [{"role": "user", "content": prompt}]
        
        response = client.chat.completions.create(
            model=model_name,
            messages=messages
        )
        return response.choices[0].message.content
    except Exception as e:
        print(f"An error occurred while calling the OpenAI API: {e}")
        return ""

def savetofile(content: str, filename: str = "response.txt"):
    with open(filename, 'a', encoding='utf-8') as f:
        f.write(content + "\n---\n")

def main():
    prompt = 'Write a hello world program in python'
    
    print(f"Sending prompt to the model: {prompt[:50]}...")
    content = openaiAsker(prompt)

    if content:
        print("\n--- OpenAI Response ---")
        print(content)
        print("--------------------------")
        
        output_filename = "openai_response.txt"
        savetofile(content, output_filename)
        print(f"Response saved to '{output_filename}'.")

if __name__ == "__main__":
    main()
