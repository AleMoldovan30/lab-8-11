#pragma once
class TestService {
    private:
        void testGetAll();
        void testGetPos();
        void testAddAv();
        void testAddAu();
        void testUpdAv();
        void testUpdAu();
        void testDel();

        void testFindDate();
        void testRezervare();

        void testLive();
    public:
        TestService();
        ~TestService();
        void testAll();
};