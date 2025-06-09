task void readTask() {
    switch(step) {
        case 0:
            call Temp.read(); break;
        case 1:
            call Humi.read(); break;
        case 2:
            call Illu.read(); break;
        default:
            testMsg->battery = call Battery.getVoltage();
            post sendTask();
            break;
    }
    step += 1;
}
