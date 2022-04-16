import pickle
from PIL import Image

with open('D:/zh_dbp15k_link_img_dict_full.pkl', 'rb') as f:
    da = f.readlines()
    print(da[:6])
