# paMcuLibDemo_esp32
paMcuLib demo project for esp32

paMcuLib esp32平台的例程

[to know more about paMculib](https://github.com/ActivePeter/paMcuLib)

了解更多关于paMcuLib的信息

### Start dev/开始开发

- ### 1.prepare the necessary environment

  ### 1.准备必要的环境

  - 1.1 vscode
  - 1.2 idf with vscode
  - 1.3 vscode extensions
    - ![image-20210708014653887](https://hanbaoaaa.xyz/tuchuang/images/2021/07/07/image-20210708014653887.png)
    - ![image-20210708014726114](https://hanbaoaaa.xyz/tuchuang/images/2021/07/07/image-20210708014726114.png)
    - ![image-20210708014835092](https://hanbaoaaa.xyz/tuchuang/images/2021/07/07/image-20210708014835092.png)

- ### 2. git clone this project

- ### 3. open this project with vscode

  ### 3.用vscode 打开这个项目

  - 3.1 **submodule_helper.json**  check this file to know about submodules

    3.1 检查这个文件来了解子模块结构

    - **ctrl+shift+p** open command palette

      打开命令面板

    - select this command

      选择这个命令

      ![image-20210708015158211](https://hanbaoaaa.xyz/tuchuang/images/2021/07/07/image-20210708015158211.png)

    - then you will see the modules directories will be loaded with contents

      然后你可以看到子模块文件夹里会加载内容

      - ![image-20210708015324084](https://hanbaoaaa.xyz/tuchuang/images/2021/07/07/image-20210708015324084.png)

      - that means the submodules are loaded successfully

        那意味着子模块加载成功了

  - 3.1 right click on side bar and select the second one 

    3.1 右击侧边栏并选择第二项

    - ![image-20210708015440204](https://hanbaoaaa.xyz/tuchuang/images/2021/07/07/image-20210708015440204.png)

    - you can see a structure of config

      你可以看到一个配置结构

      you can **switch the demo config** and set the **gpio of ili9341**

      你可以切换demo的设置以及设置ili9341的gpio

      remember to connect the screen as the config

      记得照着配置连好屏幕

      ![image-20210708015606182](https://hanbaoaaa.xyz/tuchuang/images/2021/07/07/image-20210708015606182.png)

    - then right click the side panel and select **3rd part** to **generate config headers**

      然后右击侧边栏选择第三项来生成conf头文件

      ![image-20210708015840828](https://hanbaoaaa.xyz/tuchuang/images/2021/07/07/image-20210708015840828.png)

      headers are generated in target path

      头文件会被生成到目标路径中

      ![image-20210708015917501](https://hanbaoaaa.xyz/tuchuang/images/2021/07/07/image-20210708015917501.png)

  - ### 3.2 compile with idf 

    ### 3.2 使用idf编译

    - ![image-20210708020042503](https://hanbaoaaa.xyz/tuchuang/images/2021/07/07/image-20210708020042503.png)

    - after loaded, the screen turned to black after inited.

      加载完成后，屏幕会变成黑色，

      ![image-20210708020131093](https://hanbaoaaa.xyz/tuchuang/images/2021/07/07/image-20210708020131093.png)





