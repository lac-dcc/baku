import pandas as pd


class DataLoader:
    def __init__(self, data_path:str):
        try:
            self.data_path = data_path
            self.dataframe = pd.read_csv(data_path)
            print("Data Loaded.")
        except:
            raise Exception("Data couldn't be loaded.")


    def save(self):#Save the modified csv
        try:
            self.dataframe.to_csv(self.data_path, index=False)
            print("All data updated.")
        except:
            raise Exception("Data couldn't be uploaded.")

    def column_values(self,column_name):#Get a list of values in a column
        try:
            return self.dataframe[column_name].values
        except:
            raise Exception("Column must be wrong.")

    def new_row(self, new_values: list):#Matches two list to form a new data row
      if len(new_values) != len(self.dataframe.columns):
          raise ValueError("The number of values does not match the number of columns.")

      # Create a DataFrame from the new row values
      new_row = pd.DataFrame([dict(zip(self.dataframe.columns, new_values))])

      self.dataframe = pd.concat([self.dataframe, new_row], ignore_index=True)
      
    def update_row(self,index: str, new_values:list):
        if len(new_values) != len(self.dataframe.columns):
            raise ValueError("The number of values does not match the number of columns.")
        self.dataframe = self.dataframe.set_index(index) 
        self.dataframe.loc[new_values[0]] = new_values[1:]
        self.dataframe = self.dataframe.reset_index()


    def get_row(self, column: str, key: any):#Get all row using a key
        row = self.dataframe.set_index(column).loc[[key]]  # [[key]] to ensure good research
        values = row.values.flatten().tolist()
        return values

    def static_row_string(self,id,ignore_columns=""):#Choose a value to generate
        if(id==0):
            return "Impossible to pick the value."

        else:

            if not ignore_columns == "": #if there is a column...
                static = self.dataframe.drop(ignore_columns, axis=1).iloc[id]

            else:
                static = self.dataframe.iloc[id]

            static = static.to_string(index=False)
            return static

    def random_row_string(self,ignore_columns=""):#Random pick value to generates
        random = self.dataframe.sample()
        id = random.get('id').values[0]

        if not ignore_columns == "":#if there is a column...
            random = random.drop(ignore_columns, axis=1)

        random = random.to_string(index=False)
        return random,id

    def get_size(self):
        return len(self.dataframes.index)

