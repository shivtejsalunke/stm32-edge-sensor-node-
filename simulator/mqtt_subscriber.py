"""Optional Paho MQTT subscriber with TLS verification enabled by default."""
import argparse
import ssl

def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--host", required=True)
    parser.add_argument("--port", type=int, default=8883)
    parser.add_argument("--topic", default="demo/shivtej/sensor-node/telemetry")
    parser.add_argument("--ca", help="path to trusted CA certificate")
    parser.add_argument("--insecure-local-demo", action="store_true",
                        help="disable TLS only for isolated local demonstrations")
    args = parser.parse_args()
    try:
        import paho.mqtt.client as mqtt
    except ImportError:
        parser.error("install optional subscriber dependency with: pip install paho-mqtt==2.1.0")

    client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2)
    if args.insecure_local_demo:
        client.tls_set(cert_reqs=ssl.CERT_NONE)
        client.tls_insecure_set(True)
        print("WARNING: TLS verification disabled; use only on an isolated local demo network")
    else:
        client.tls_set(ca_certs=args.ca, cert_reqs=ssl.CERT_REQUIRED,
                       tls_version=ssl.PROTOCOL_TLS_CLIENT)
    def on_connect(client, userdata, flags, reason_code, properties):
        if reason_code.is_failure:
            print(f"MQTT connection failed: {reason_code}")
            return
        client.subscribe(args.topic)
        print(f"Subscribed to {args.topic}")
    def on_message(client, userdata, message):
        print(f"{message.topic}: {message.payload.decode('utf-8', errors='replace')}")
    client.on_connect = on_connect
    client.on_message = on_message
    client.connect(args.host, args.port, keepalive=60)
    try:
        client.loop_forever()
    except KeyboardInterrupt:
        pass
    finally:
        client.disconnect()

if __name__ == "__main__":
    main()
