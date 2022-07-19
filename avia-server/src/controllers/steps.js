import { stepsModel } from "../db/model/steps";

async function addStep(req, res) {
  try {
    await stepsModel.create({ createAt: Date.now() });
  } catch (e) {
    return res.status(500).send("Something went wrong");
  }

  return res.status(200).send("");
}

async function calcStepsCount(req, res) {
  const { startAt: startAtStr, endAt:endAtStr } = req.query;
  const startAt = parseInt(startAtStr,10);
  const endAt =parseInt(endAtStr??Date.now(),10)

  const resDb = await stepsModel.countDocuments({
    $and: [{ createAt: { $gte: startAt } }, { createAt: { $lte: endAt } }],
  });

  res.json({count:resDb});
}

export { addStep, calcStepsCount };
