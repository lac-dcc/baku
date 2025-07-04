import os
from google import genai

api_key = os.getenv("GEMINI_API_KEY")

def geminiAsker(prompt:str, model:str = "gemini-1.5-flash") -> str:
    client = genai.Client()
    response = client.models.generate_content(
        model=model,
        contents=prompt
    )
    return response

def savetofile(response: str, filename: str = "response.txt"):
    with open(filename, 'a', encoding='utf-8') as f:
        f.write(response)

def main():
    prompt = 'Write a hello world program in python'
    response = geminiAsker(prompt)
    content = response.text
    print(content)
    savetofile(content, "response.txt")

if __name__ == "__main__":
    main()