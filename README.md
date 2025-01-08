**Hello!**
There was a problem in one project: TCP-classes in Qt can't send big messages and files without some manipulations. Well, i will try fix it)
**Status**: in work.

**Task**: create "shell" for a client and server in QT (QTcpSocket & QTcpServer). 
They must can do:
  1. Sending/writting multiformat messages (bytes, text, files);
  2. Support multiple connections on the server;
  3. Can at the same time send and read messages at multiple clients;
  4. Automatic numerating client (create id);

