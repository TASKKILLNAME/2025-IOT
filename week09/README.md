# 무선 네트워크 9주차 핵심 요약

## Wi-Fi (IEEE 802.11)

### 주요 특징
- **구성**: AP(Access Point) + STA(Station)
- **MAC 방식**: DCF(CSMA/CA), PCF(Polling) 선택사양
- **Service Set**: BSS(기본) → ESS(확장)

### CSMA/CA 동작
1. **Carrier Sensing** → 채널 사용 여부 확인
2. **Backoff** → 랜덤 시간 대기
3. **RTS-CTS-DATA-ACK** 순서로 전송
4. **Hidden Terminal Problem** 해결을 위해 RTS/CTS 사용

### MAC Data Frame 구조
- Frame Control(2) + Sequence Number(1) + Address Info(4~20) + Data Payload + FCS(2)
- **주소 체계**: 4가지 케이스로 To DS/From DS 플래그에 따라 결정

---

## 🔗 ZigBee (IEEE 802.15.4)

### 물리(PHY) 계층
- **주파수**: 3개 밴드 27개 채널 (868MHz/915MHz/2.4GHz)
- **변조**: DSSS (Direct Sequence Spread Spectrum)
- **채널 충돌**: 2.4GHz에서 Wi-Fi와 겹침 (Ch.25,26 독립적)

### MAC 계층 특징
- **기기 종류**: NC(코디네이터), FFD(전기능), RFD(축소기능)
- **통신 방식**:
  - Non-Beacon: Non-slotted CSMA/CA (간단, sleep 어려움)
  - Beacon: Slotted CSMA/CA + 슈퍼프레임 (복잡, sleep 가능)

### 슈퍼프레임 구조
```
[Beacon] [CAP: 경쟁구간] [CFP: GTS 예약구간] [Inactive: 절전구간]
```
- **CAP**: 슬롯 단위 경쟁 전송
- **CFP**: 0~7개 GTS(Guaranteed Time Slot) 할당 가능
- **Inactive**: 송수신기 OFF로 전력 절약

### 주소 체계
- **Extended Address**: 64bit (IEEE 고유주소)
- **Short Address**: 16bit (네트워크 할당주소)
- **MAC 주소**: PAN ID(2) + Address(2 or 8)

### 분산 주소 할당 (Cskip)
**공식**: `Cskip(d) = (1+Cm-Rm-Cm*Rm^(Lm-d-1))/(1-Rm)`

**변수**:
- Cm: 최대 자식 수
- Lm: 최대 깊이
- Rm: 최대 라우터 수
- d: 현재 깊이

**장점**: 중앙집중 방식 대비 네트워크 트래픽 감소

---

## 주요 차이점

| 항목 | Wi-Fi | ZigBee |
|------|-------|---------|
| 목적 | 고속 데이터 통신 | 저전력 센서 네트워크 |
| 전력 | 높음 | 매우 낮음 |
| 속도 | 높음 (Mbps) | 낮음 (kbps) |
| 거리 | 중간 (~100m) | 짧음 (~10-50m) |
| RTS/CTS | 사용 | 사용 안함 |
| 슬롯 | 없음 | 슈퍼프레임 슬롯 |
