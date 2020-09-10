<h1 align="center">
  <br>
  GL2020-AppList-Manager
  <br>
</h1>

<h4 align="center">AppList Manager for GL2020</h4>
</br>
<p align="center">
  <a href="https://opensource.org/licenses/MIT">
    <img src="https://img.shields.io/badge/License-MIT-blue.svg" alt="License MIT">
  </a>
</p>
</br>

## Launch Options (Args)
```
-v
returns program version.
```

```
-D
delete old AppList before creating a new one.
```

</br>

## Adding Game/DLC in the list
</br>
Format: ID = NAME

Example: 382310 = ECO

Add the Games or DLC inside the file "AppListIndex.txt" 

Example:

```
582010 = Monster Hunter: World
1118010 = Monster Hunter World: Iceborne
``` 

Hint: use [Get DLC Info from SteamDB](https://github.com/Sak32009/GetDLCInfoFromSteamDB) using "APPID = APPIDNAME".

## Using
</br>

1. Place the files "AppList-Manager.exe" and "AppListIndex.txt" inside the same folder as the GL2020

2. Follow the "Adding Game/DLC in the list"

3. Opens "AppList-Manager.exe" with CMD or Powershell.

4. Done.

</br>

## Todo

- comment support
- line-break support

</br>

## 📝License
This project is under [MIT license](LICENSE).