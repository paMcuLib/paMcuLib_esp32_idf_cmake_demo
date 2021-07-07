# paMcuLibDemo_esp32
paMcuLib demo project for esp32

[to know more about paMculib](https://github.com/ActivePeter/paMcuLib)

### Start dev

- ### 1.prepare the necessary environment

  - 1.1 vscode
  - 1.2 idf with vscode
  - 1.3 vscode extensions
    - ![image-20210708014653887](https://hanbaoaaa.xyz/tuchuang/images/2021/07/07/image-20210708014653887.png)
    - ![image-20210708014726114](https://hanbaoaaa.xyz/tuchuang/images/2021/07/07/image-20210708014726114.png)
    - ![image-20210708014835092](https://hanbaoaaa.xyz/tuchuang/images/2021/07/07/image-20210708014835092.png)

- ### 2. git clone this project

- ### 3. open this project with vscode

  - 3.1 **submodule_helper.json**  check this file to know about submodules

    - **ctrl+shift+p** open command palette
    - ![image-20210708015158211](https://hanbaoaaa.xyz/tuchuang/images/2021/07/07/image-20210708015158211.png)
    - then you will see the modules directories will be filled with contents
      - ![image-20210708015324084](https://hanbaoaaa.xyz/tuchuang/images/2021/07/07/image-20210708015324084.png)
      - that means the submodules are loaded successfully

  - 3.1 right click on side bar and select the second one

    - ![image-20210708015440204](https://hanbaoaaa.xyz/tuchuang/images/2021/07/07/image-20210708015440204.png)

    - you can see a structure of config

      you can **switch the demo config** and set the **gpio of ili9341**

      ![image-20210708015606182](https://hanbaoaaa.xyz/tuchuang/images/2021/07/07/image-20210708015606182.png)

    - then right click the side panel and select **3rd part** to **generate config headers**

      ![image-20210708015840828](https://hanbaoaaa.xyz/tuchuang/images/2021/07/07/image-20210708015840828.png)

      headers are generated in target path

      ![image-20210708015917501](https://hanbaoaaa.xyz/tuchuang/images/2021/07/07/image-20210708015917501.png)

  - ### 3.2 compile with idf 

    - ![image-20210708020042503](https://hanbaoaaa.xyz/tuchuang/images/2021/07/07/image-20210708020042503.png)

    - the screen turned to black after inited.

      ![image-20210708020131093](https://hanbaoaaa.xyz/tuchuang/images/2021/07/07/image-20210708020131093.png)





