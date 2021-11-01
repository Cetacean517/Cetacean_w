package N422chat.bean;

import java.net.Socket;

//实体类，存储在线用户和用户连接信息
public class ClientBean {
    private String name;    // 用户的姓名
    private Socket socket;    // 该用户所分配的套接字

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Socket getSocket() {
        return socket;
    }

    public void setSocket(Socket socket) {
        this.socket = socket;
    }
}
