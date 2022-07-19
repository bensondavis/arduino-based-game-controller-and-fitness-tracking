import axios from "axios";

const serverUrl = "http://localhost:9000";

async function getStepCount(startAt, endAt) {
  const res = await axios(
    `${serverUrl}/steps/count?startAt=${startAt}&endAt=${endAt}`
  );
  return res.data;
}

export { getStepCount };
