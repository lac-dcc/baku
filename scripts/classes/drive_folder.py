from googleapiclient.discovery import build
from googleapiclient.http import MediaFileUploadclass 
import string

class Drive:
    
    @staticmethod
    def upload_single_file_to_drive(folder_id,code_name,program):#Upload file to drive for colab
        try:
            local_file_path = f"/content/{code_name}.c"


            with open(local_file_path, "w") as file:
                file.write(program)


            file_metadata = {
                'name': f'{code_name}.c',
                'parents': [folder_id]
            }

            media = MediaFileUpload(local_file_path, mimetype='text/plain')
            service = build('drive', 'v3')
            uploaded_file = service.files().create(body=file_metadata, media_body=media, fields='id').execute()

            print(f"File uploaded successfully. File ID: {uploaded_file.get('id')}")
        except Exception as e:
            print(f"File could not be uploaded. ERROR: {e}")

    @staticmethod
    def upload_chain_file_to_drive(program,folder_id,folder_name,n):#Upload file to drive for colab
        try:
            local_file_path = f"/content/{folder_name}{n}.c"


            with open(local_file_path, "w") as file:
                file.write(program)


            file_metadata = {
                'name': f'{folder_name}{n}.c',
                'parents': [folder_id]
            }

            media = MediaFileUpload(local_file_path, mimetype='text/plain')
            service = build('drive', 'v3')
            uploaded_file = service.files().create(body=file_metadata, media_body=media, fields='id').execute()

            print(f"File uploaded successfully. File ID: {uploaded_file.get('id')}")
        except Exception as e:
            print(f"File could not be uploaded. ERROR: {e}")

    @staticmethod
    def folder_generator(folder_data,parent_folder_id,size=4):
        try:
            chars=string.ascii_uppercase
            random_name = ''.join(random.choice(chars) for _ in range(size))
            while random_name in folder_data.column_values('folder_id'):
                random_name = ''.join(random.choice(chars) for _ in range(size))

            folder_metadata = {
                'name': random_name,
                'mimeType': 'application/vnd.google-apps.folder'
            }

            if parent_folder_id:
                folder_metadata['parents'] = [parent_folder_id]

            service = build('drive', 'v3')
            created_folder = service.files().create(
                body=folder_metadata,
                fields='id'
            ).execute()

            return created_folder.get('id'),random_name
        except Exception as e:
            raise f"Folder coulnd't been created: {e}"

    @staticmethod
    def find_folder(parent_folder_id: str, folder_name: str):
        try:
            drive_service = build('drive', 'v3')

            query = f"'{parent_folder_id}' in parents and name = '{folder_name}' and mimeType = 'application/vnd.google-apps.folder'"

            results = drive_service.files().list(
                q=query,
                fields='files(id, name)'
            ).execute()

            folders = results.get('files', [])

            if folders:
                return folders[0]['id'], folders[0]['name']
            else:
                return None, None

        except Exception as e:
            raise f"Folder coulnd't been founded: {e}"

    @staticmethod
    def create_folder(parent_folder_id: str, folder_name: str):
        try:
            drive_service = build('drive', 'v3')

            folder_metadata = {
                'name': folder_name,
                'mimeType': 'application/vnd.google-apps.folder'
            }

            if parent_folder_id:
                folder_metadata['parents'] = [parent_folder_id]

            service = build('drive', 'v3')
            created_folder = service.files().create(
                body=folder_metadata,
                fields='id'
            ).execute()

            return created_folder.get('id'),folder_name
        except Exception as e:
            raise f"Folder coulnd't been created: {e}"

    @staticmethod
    def create_folder_model(parent_folder_id: str, folder_name: str):
        try:
            drive_service = build('drive', 'v3')

            folder_metadata = {
                'name': folder_name,
                'mimeType': 'application/vnd.google-apps.folder'
            }

            if parent_folder_id:
                folder_metadata['parents'] = [parent_folder_id]

            service = build('drive', 'v3')
            
            created_folder = service.files().create(
                body=folder_metadata,
                fields='id'
            ).execute()

                
            csv_contents = [
                "model,mean_seconds,std_seconds,sample_size,max_length,lower_value,higher_value",
                "model_name,seconds,code_name,caracteristcs,length",
                "folder_name"
            ]
            
            csv_names = ["sampling", "model_codes", "folders"]

            for content, name in zip(csv_contents, csv_names):
                local_path = f"/content/{name}.csv"
                
                with open(local_path, "w") as f:
                    f.write(content)
                
                # Upload para o Drive
                file_metadata = {
                    'name': f'{name}.csv',
                    'parents': [created_folder['id']]
                }
                
                media = MediaFileUpload(local_path, mimetype='text/csv')
                
                service.files().create(
                    body=file_metadata,
                    media_body=media,
                    fields='id'
                ).execute()
            

            return created_folder.get('id'),folder_name
        except Exception as e:
            raise f"Folder coulnd't been created: {e}"